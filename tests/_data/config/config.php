<?php

return array(
        "phalcon" => array(
            "baseuri" => "/phalcon/"
        ),
        "models" => array(
            "metadata" => "memory"
        ),
        "database" => array(
            "adapter" => "mysql",
            "host" => "localhost",
            "username" => "user",
            "password" => "passwd",
            "name" => "demo"
        ),
        "test" => array(
            "parent" => array(
                "property" => 1,
                "property2" => "yeah"
            ),
        )
    );
