CREATE OR REPLACE FUNCTION circle(rad float)
RETURNS float AS $$
DECLARE area float;
BEGIN
	area := rad*3.14*3.14;

	BEGIN
		EXCEPTION
			WHEN data_exception THEN
				RAISE NOTICE 'no data found';
			WHEN too_many_arguments THEN
				RAISE NOTICE 'too many arguments in the call';
			WHEN others THEN
				RAISE NOTICE 'unknown error';	        
	END;

	RETURN area;
END;
$$ LANGUAGE plpgsql STRICT;


select circle(98);
