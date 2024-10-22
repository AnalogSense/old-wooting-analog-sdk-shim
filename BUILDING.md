This project uses [Sun](http://github.com/calamity-inc/Sun).

## 32-bit specific notes

For 32-bit, [Soup](https://github.com/calamity-inc/Soup) is also needed.

The directory struture is expected to look like this:
```
AnalogSense/
	old-wooting-analog-sdk-shim/
Soup/
```

The following needs to be added to `Soup/soup/.sun` and `Soup/Intrin/.sun`:
```
arg -m32
```

Yes, I know it would be easier for you if I had created a Visual Studio project, but, oh well!
