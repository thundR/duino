[System.IO.Ports.SerialPort]::getportnames()
$port= new-Object System.IO.Ports.SerialPort COM9,9600,None,8,one
$port.open()
$port.Write(3)
$port.Write(4)
$port.Close()