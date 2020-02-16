



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
            




drop table if exists hardware.robot;            
            
create table hardware.robot
(
  robot_id serial not null
    constraint robot_pk
      primary key,
  robot_name varchar(70)
);
            
alter table hardware.robot owner to postgres;
            


drop table if exists public.robot_part;            
            
create table public.robot_part
(
  robot_part_id serial not null
    constraint robot_part_pk
      primary key,
  robot_part_name varchar(70)
);
            
alter table public.robot_part owner to postgres;
            


drop table if exists private.robot_to_robot_part;
            
create table private.robot_to_robot_part
(
  robot_id int not null,
  robot_part_id int not null
);
            
alter table private.robot_to_robot_part owner to postgres;
            






