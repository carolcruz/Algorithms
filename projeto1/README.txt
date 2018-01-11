The port automation company Poxim Tech is developing a system for automated handling of cargo containers of international origin at the Port of Sergipe to maximize the efficiency of customs inspection.
	- All the containers have an electronic register containing information about the code of the container, the code 		  of the importing company and the net weight in kilograms of the cargo;
	- Container inspection is performed whenever there is any divergence between the registered information, such as 		  the company code informed or the percentage difference greater than 10% in net weight;
	- In the triage of the containers are inspected the containers with the following order of priority:
		1. Divergence of company code
		2. Greater percentage difference of net weight

INPUT:

	[#n number of containers]
	[Container's code 1] [Company's code 1] [Weight 1]
			···
	[Container's code n] [Company's code n] [Weight n]
	[#m number of selected containers]
	[Container's code 1] [Company's code 1] [Weight 1]
			···
	[Container's code m] [Company's code m] [Weight m]

	EXAMPLE:
		6
		QOZJ7913219 34.699.211/9365-11 13822
		FCCU4584578 50.503.434/5731-28 16022
		KTAJ0603546 20.500.522/6013-58 25279
		ZYHU3978783 43.172.263/4442-14 24543
		IKQZ7582839 51.743.446/1183-18 12160
		HAAZ0273059 25.699.428/4746-79 16644
		5
		ZYHU3978783 43.172.263/4442-14 29765
		IKQZ7582839 51.743.446/1113-18 18501
		KTAJ0603546 20.500.522/6113-58 17842
		QOZJ7913219 34.699.211/9365-11 16722
		FCCU4584578 50.503.434/5731-28 16398

OUTPUT:

	KTAJ0603546: 20.500.522/6013-58<->20.500.522/6113-58
	IKQZ7582839: 51.743.446/1183-18<->51.743.446/1113-18
	QOZJ7913219: 2900kg (21%)
	ZYHU3978783: 5222kg (21%)
