DROP TABLE IF EXISTS "complex_default";

create table complex_default
(
    id           SERIAL PRIMARY KEY,
    created      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_null TIMESTAMP NULL DEFAULT NULL
);

CREATE OR REPLACE FUNCTION update_timestamp()
RETURNS TRIGGER AS $$
BEGIN
   NEW.updated = NOW(); 
   NEW.updated_null = NOW();
   RETURN NEW;
END;
$$ language 'plpgsql';

CREATE TRIGGER update_timestamp BEFORE UPDATE
ON complex_default FOR EACH ROW EXECUTE PROCEDURE 
update_timestamp();
