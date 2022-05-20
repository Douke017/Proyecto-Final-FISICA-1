from serialToExcel import SerialToExcel

serialToExcel = SerialToExcel("COM36",115200)

columnas = ["Nro Lectura","Valor"]

serialToExcel.setColumns(["Nro Lectura","Valor"])
serialToExcel.setRecordsNumber(10)
serialToExcel.readPort()
