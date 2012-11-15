SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;
COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';
SET search_path = public, pg_catalog;
SET default_tablespace = '';
SET default_with_oids = false;

SELECT 'DROP TABLE "' || tablename || '" CASCADE;' FROM pg_tables WHERE schemaname = 'public';

DROP USER IF EXISTS phalcon_user;
CREATE USER phalcon_user WITH PASSWORD '1234';
GRANT ALL PRIVILEGES ON DATABASE phalcon_test TO phalcon_user;

-- Table: customers
CREATE TABLE customers (
  id integer NOT NULL,
  document_id integer NOT NULL,
  customer_id character varying(15) NOT NULL,
  first_name character varying(100) DEFAULT NULL::character varying,
  last_name character varying(100) DEFAULT NULL::character varying,
  phone character varying(20) DEFAULT NULL::character varying,
  email character varying(70) NOT NULL,
  instructions character varying(100) DEFAULT NULL::character varying,
  status character(1) NOT NULL,
  birth_date date DEFAULT '1970-01-01'::date,
  credit_line numeric(16,2) DEFAULT '0',
  created_at date DEFAULT NULL,
  created_at_user_id integer DEFAULT '0'
);
ALTER TABLE public.customers OWNER TO postgres;

CREATE SEQUENCE customers_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;

ALTER TABLE public.customers_id_seq OWNER TO postgres;
ALTER SEQUENCE customers_id_seq OWNED BY customers.id;
SELECT pg_catalog.setval('customers_id_seq', 1, false);

ALTER TABLE ONLY customers ALTER COLUMN id SET DEFAULT nextval('customers_id_seq'::regclass);
ALTER TABLE ONLY customers ADD CONSTRAINT customers_pkey PRIMARY KEY (id);
CREATE INDEX customer_document_id_idx ON customers(document_id);
CREATE INDEX customer_customer_id_idx ON customers(customer_id);
CREATE INDEX customer_status_idx ON customers(status, last_name, first_name);


-- Table: parts
CREATE TABLE parts (
    id integer NOT NULL,
    name character varying(70) NOT NULL
);
ALTER TABLE public.parts OWNER TO postgres;
CREATE SEQUENCE parts_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
ALTER TABLE public.parts_id_seq OWNER TO postgres;
ALTER SEQUENCE parts_id_seq OWNED BY parts.id;
SELECT pg_catalog.setval('parts_id_seq', 1, false);

ALTER TABLE ONLY parts ALTER COLUMN id SET DEFAULT nextval('parts_id_seq'::regclass);
ALTER TABLE ONLY parts ADD CONSTRAINT parts_pkey PRIMARY KEY (id);


-- Table: robots
CREATE TABLE robots (
    id integer NOT NULL,
    name character varying(70) NOT NULL,
    type character varying(32) NOT NULL,
    year integer NOT NULL
);
ALTER TABLE public.robots OWNER TO postgres;
CREATE SEQUENCE robots_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
ALTER TABLE public.robots_id_seq OWNER TO postgres;
ALTER SEQUENCE robots_id_seq OWNED BY robots.id;
SELECT pg_catalog.setval('robots_id_seq', 1, false);

ALTER TABLE ONLY robots ALTER COLUMN id SET DEFAULT nextval('robots_id_seq'::regclass);
ALTER TABLE ONLY robots ADD CONSTRAINT robots_pkey PRIMARY KEY (id);


-- Table: robots
CREATE TABLE robots_parts (
    id integer NOT NULL,
    robots_id integer NOT NULL,
    parts_id integer NOT NULL,
);
ALTER TABLE public.robots_parts OWNER TO postgres;
CREATE SEQUENCE robots_parts_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
ALTER TABLE public.robots_parts_id_seq OWNER TO postgres;
ALTER SEQUENCE robots_parts_id_seq OWNED BY robots_parts.id;
SELECT pg_catalog.setval('robots_parts_id_seq', 1, false);

ALTER TABLE ONLY robots_parts ALTER COLUMN id SET DEFAULT nextval('robots_parts_id_seq'::regclass);
ALTER TABLE ONLY robots_parts ADD CONSTRAINT robots_parts_pkey PRIMARY KEY (id);

CREATE INDEX robots_parts_parts_id ON robots_parts USING btree (parts_id);
CREATE INDEX robots_parts_robots_id ON robots_parts USING btree (robots_id);

ALTER TABLE ONLY robots_parts
    ADD CONSTRAINT robots_parts_ibfk_1 FOREIGN KEY (robots_id) REFERENCES robots(id);
ALTER TABLE ONLY robots_parts
    ADD CONSTRAINT robots_parts_ibfk_2 FOREIGN KEY (parts_id) REFERENCES parts(id);




REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;
