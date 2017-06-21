Insert into ROOM values ('GM01', 'P2', 1111); 
Insert into ROOM values ('GM02', 'P2', 1112); 
Insert into ROOM values ('GM03', 'P2', 1113); 
Insert into ROOM values ('GM04', 'P2', 1114); 
Insert into ROOM values ('IC01', 'P1', 2221); 
Insert into ROOM values ('IC02', 'P1', 2222); 
Insert into ROOM values ('IC03', 'P1', 2223); 


Insert into PATIENTS values (1111, '15-DEC-01', '20-DEC-01', 'Tom Thumb', 'GM03'); 
Insert into PATIENTS values (1117, '16-DEC-01', '22-DEC-01', 'Sally Field', 'GM01'); 
Insert into PATIENTS values (1113, '17-DEC-01', '21-DEC-01', 'George Marshall', 'GM03'); 
Insert into PATIENTS values (1114, '15-DEC-01', '24-DEC-01', 'William Clinton', 'GM02'); 
Insert into PATIENTS values (1116, '18-DEC-01', '22-DEC-01', 'G. W. Bush', 'IC01'); 
Insert into PATIENTS values (1115, '15-DEC-01', '25-DEC-01', 'Barbara Streisand', 'IC03'); 
Insert into PATIENTS values (1112, '18-DEC-01', '20-DEC-01', 'Eminem', 'GM01'); 


Insert into ITEM values (2222, 'Syringe, 19 gauge', 7.54); 
Insert into ITEM values (2233, '9 inch gauze', 2.21); 
Insert into ITEM values (2244, 'Tylenol 800MG', 4.50); 
Insert into ITEM values (2223, 'Morphine Drip, 0.2 liter', 284.59); 
Insert into ITEM values (2255, 'Saline Soln, 1 liter', 25.00); 
Insert into ITEM values (2243, 'Syringe, 8 gauge', 6.68); 
Insert into ITEM values (2267, 'Bed Pan', 4.92); 
Insert into ITEM values (2266, 'Surgical Prep Pack #2', 195.95); 
Insert into ITEM values (2265, '4 inch gauze', 1.19); 
Insert into ITEM values (2245, 'Surgical Prep Pack #8', 167.67); 
Insert into ITEM values (2268, 'Bandaid, 3 inch', 0.76); 
Insert into ITEM values (2242, '4 inch dressing', 4.56); 
Insert into ITEM values (2224, 'Surgical Prep Pack #4', 222.21); 


Insert into PHYSICIAN values (8880, '888-0001', 'Dr. Oprah Heart'); 
Insert into PHYSICIAN values (8887, '888-0007', 'Dr. Hawkeye Pierce'); 
Insert into PHYSICIAN values (8882, '888-0002', 'Dr. Jonas Salkman'); 
Insert into PHYSICIAN values (8884, '888-0004', 'Dr. Winifred Winfield'); 
Insert into PHYSICIAN values (8886, '888-0006', 'Dr. Trapper John'); 


Insert into PROCEDURES values (3225, 'Appendectomy'); 
Insert into PROCEDURES values (3233, 'Lobotomy'); 
Insert into PROCEDURES values (3234, 'Thoracic Procedure'); 
Insert into PROCEDURES values (3232, 'Cervical Disk'); 
Insert into PROCEDURES values (3230, 'Hip Replacement'); 
Insert into PROCEDURES values (3231, 'Arthroscopic Procedure'); 
Insert into PROCEDURES values (3237, 'Ingrown Toenail'); 


Insert into TREATS values (8887, 1117, 3232, '17-DEC-01','Repaired Disk OK'); 
Insert into TREATS values (8882, 1113, 3230, '18-DEC-01','Repaired Right Hip OK'); 
Insert into TREATS values (8887, 1113, 3232, '17-DEC-01','Repaired Disk OK'); 
Insert into TREATS values (8884, 1114, 3233, '15-DEC-01','Brain Partially Removed'); 
Insert into TREATS values (8886, 1116, 3234, '19-DEC-01','Removed Left Lung'); 
Insert into TREATS values (8880, 1111, 3237, '15-DEC-01','Removed toenail'); 
Insert into TREATS values (8886, 1115, 3230, '17-DEC-01','Repaired Left Hip OK'); 
Insert into TREATS values (8887, 1112, 3231, '18-DEC-01','Repaired Left Knee OK'); 
Insert into TREATS values (8887, 1112, 3231, '19-DEC-01','Repaired Right Knee OK'); 


Insert into BILLED values (11111, 1111, 2222, 7.54); 
Insert into BILLED values (11112, 1112, 2242, 4.56); 
Insert into BILLED values (11113, 1113, 2266, 195.95); 
Insert into BILLED values (11114, 1114, 2233, 2.21); 
Insert into BILLED values (11115, 1115, 2243, 6.68); 
Insert into BILLED values (11116, 1116, 2268, 0.76); 