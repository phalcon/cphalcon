

drop table if exists co_invoices;
            
create table co_invoices
(
    inv_id          serial not null constraint co_invoices_pk primary key,
    inv_cst_id      integer,
    inv_status_flag smallint,
    inv_title       varchar(100),
    inv_total       numeric(10, 2),
    inv_created_at  timestamp
);
            
alter table co_invoices owner to postgres;
            
create index co_invoices_inv_created_at_index
    on co_invoices (inv_created_at);
            
create index co_invoices_inv_cst_id_index
    on co_invoices (inv_cst_id);
            
create index co_invoices_inv_status_flag_index
    on co_invoices (inv_status_flag);
            


drop table if exists objects;
            
create table objects
(
    obj_id   serial       not null constraint co_objects_pk primary key,
    obj_name varchar(100) not null,
    obj_type smallint     not null
);
            
alter table objects owner to postgres;
            


drop table if exists co_sources;
            
create table co_sources
(
    id        serial not null constraint co_sources_pk primary key,
    username  varchar(100),
    source    varchar(100)
);
            
alter table co_sources owner to postgres;
            
create index co_sources_username_index
    on co_sources (username);
            


drop table if exists table_with_uuid_primary;
            
create table table_with_uuid_primary
(
    uuid          char(36) not null constraint uuid_pk primary key,
    int_field     integer
);
            
alter table table_with_uuid_primary owner to postgres;
            


drop table if exists stuff;
            
create table stuff
(
    stf_id   serial         not null constraint stuff_pk primary key,
    stf_name varchar(100)   not null,
    stf_type smallint       not null
);
            
alter table stuff owner to postgres;
            
