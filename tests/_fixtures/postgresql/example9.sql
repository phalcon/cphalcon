SELECT COUNT(tc.constraint_name)
    FROM information_schema.table_constraints tc
      INNER JOIN information_schema.key_column_usage kcu
        ON tc.constraint_catalog = kcu.constraint_catalog
           AND tc.constraint_schema = kcu.constraint_schema
           AND tc.constraint_name = kcu.constraint_name
      INNER JOIN information_schema.referential_constraints rc
        ON tc.constraint_catalog = rc.constraint_catalog
           AND tc.constraint_schema = rc.constraint_schema
           AND tc.constraint_name = rc.constraint_name
           AND  tc.constraint_type = 'FOREIGN KEY'
      INNER JOIN information_schema.constraint_column_usage ccu
        ON rc.unique_constraint_catalog = ccu.constraint_catalog
           AND rc.unique_constraint_schema = ccu.constraint_schema
           AND rc.unique_constraint_name = ccu.constraint_name
    WHERE tc.constraint_name = '%_FK_%'
          AND rc.update_rule = 'RESTRICT'
          AND rc.delete_rule = 'CASCADE'
