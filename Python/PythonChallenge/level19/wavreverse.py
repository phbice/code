#wav reverse
#2018-8-17 20:39

import wave
wi = wave.open('indian.wav', 'rb')
wo = wave.open('indian_out.wav', 'wb')
wo.setparams(wi.getparams())
for i in range(wi.getnframes()):
    wo.writeframes(wi.readframes(1)[::-1])
wi.close()
wo.close()