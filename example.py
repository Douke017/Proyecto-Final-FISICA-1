from serialToExcel import SerialToExcel

serialToExcel = SerialToExcel("COM3",9600)

columnas = ["Nro Lectura","Valor"]

serialToExcel.setColumns(["Nro Lectura","Valor"])
serialToExcel.setRecordsNumber(20)
serialToExcel.readPort()
serialToExcel.writeFile("TomaDeMedidas.xls")
