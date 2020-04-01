SELECT animal_type,IFNULL(name,"No name") as name, sex_upon_intake from animal_ins
-- IFNULL 은 원래값 , 대체값 의 형태로 진행된다.