import socket
import threading
import json
from cmd import Cmd
import datetime

class Client(Cmd):
    """
    客户端
    """
    prompt = ''
    intro = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n'+'[Welcome] 简易聊天室客户端\n' + '[Welcome] 输入help来获取帮助\n'

    def __init__(self):
        """
        构造
        """
        super().__init__()
        self.__socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.__id = None
        self.__nickname = None

    def __receive_message_thread(self):
        """
        接受消息线程
        """
        while True:
            # noinspection PyBroadException
            try:
                buffer = self.__socket.recv(1024).decode()
                obj = json.loads(buffer)
                print(datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n'+'[' + str(obj['sender_nickname']) + '(' + str(obj['sender_id']) + ')' + ']', obj['message'])
            except Exception:
                print(datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n'+'[Client] 无法从服务器获取数据')

    def __send_message_thread(self, message):
        """
        发送消息线程
        :param message: 消息内容
        """
        self.__socket.send(json.dumps({
            'type': 'broadcast',
            'sender_id': self.__id,
            'message': message
        }).encode())

    def start(self):
        """
        启动客户端
        """
        self.__socket.connect(('127.0.0.1', 8888))
        self.cmdloop()

    def do_login(self, args):
        """
        登录聊天室
        :param args: 参数
        """
        nickname = args.split(' ')[0]

        # 将昵称发送给服务器，获取用户id
        self.__socket.send(json.dumps({
            'type': 'login',
            'nickname': nickname
        }).encode())
        # 尝试接受数据
        # noinspection PyBroadException
        try:
            buffer = self.__socket.recv(1024).decode()
            obj = json.loads(buffer)
            if obj['id']:
                self.__nickname = nickname
                self.__id = obj['id']
                print(datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n'+'[Client] 成功登录到聊天室')

                # 开启子线程用于接受数据
                thread = threading.Thread(target=self.__receive_message_thread)
                thread.setDaemon(True)
                thread.start()
            else:
                print(datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n'+'[Client] 无法登录到聊天室')
        except Exception:
            print(datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n'+'[Client] 无法从服务器获取数据')

    def do_send(self, args):
        """
        发送消息
        :param args: 参数
        """
        message = args
        # 显示自己发送的消息
        print(datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n'+'[' + str(self.__nickname) + '(' + str(self.__id) + ')' + ']', message)
        # 开启子线程用于发送数据
        thread = threading.Thread(target=self.__send_message_thread, args=(message, ))
        thread.setDaemon(True)
        thread.start()

    def do_help(self, arg):
        """
        帮助
        :param arg: 参数
        """
        command = arg.split(' ')[0]
        if command == '':
            print(datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')+'\n')
            print('[Help] login nickname - 登录到聊天室，nickname是你选择的昵称')
            print('[Help] send message - 发送消息，message是你输入的消息')
        elif command == 'login':
            print('[Help] login nickname - 登录到聊天室，nickname是你选择的昵称')
        elif command == 'send':
            print('[Help] send message - 发送消息，message是你输入的消息')
        else:
            print('[Help] 没有查询到你想要了解的指令')
client = Client()
client.start()