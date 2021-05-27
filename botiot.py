import telebot
token = ''
bot = telebot.TeleBot(token)
import urllib.request

global m 


@bot.message_handler(commands=['start'])
def start_command(message):
    bot.send_message(message.chat.id, "Hello!")
    
    
@bot.message_handler(commands=['check'])    
def check_message(message):
    m = ''
    
    while True: 
        site = ''
        fp = urllib.request.urlopen(site)
        mybit = fp.read()
        k = mybit.decode('utf8')
        if k != m:
            m = k[len(m):]
            s = m.replace('<br/>', '\n')
            bot.send_message(message.chat.id, s)
            m = k 
            fp.close()
        
    
bot.polling()
