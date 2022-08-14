import random
import threading
import time

class threading_test:
    run_flag = threading.Event()
    run_flag.set()
    print_lock = threading.Lock()
    
    @classmethod
    def job(cls, id_):
        a = 0
        while cls.run_flag.is_set():
            cls.print_lock.acquire()
            print(id_, a)
            cls.print_lock.release()
            a += 1
            time.sleep(random.uniform(0.5,1))

'''
run_flag = threading.Event()
run_flag.set()

print_lock = threading.Lock()
'''

threads = [threading.Thread(target=threading_test.job, args=(id_,))
           for id_ in range(10)]
for thread in threads:
    thread.start()

try:
    while True: pass
except KeyboardInterrupt:
    threading_test.run_flag.clear()
