<?php
/**
 * Customers.php
 * Phalcon_Test_Fixtures_Customers
 *
 * Used to populate the tables (fixtures) in the database
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class Phalcon_Test_Fixtures_Customers
{
    public static function get($records = null)
    {
        $template = "(%s, '1', '1', '%s', '%s', '%s', '%s', '%s', 'A', "
                  . "'%s', '0.00', '%s', '0')";

        $total = (is_null($records)) ? 100 : intval($records);

        for ($i = 1; $i <= $total; $i++)
        {
            $first_name = uniqid('fn');
            $last_name  = uniqid('ln');
            $phone      = uniqid('555');
            $notes      = uniqid('notes', true);
            $birthday   = date('Y-m-d');
            $now        = date('Y-m-d H:i:s');

            $data[] = sprintf(
                $template,
                $i,
                $first_name,
                $last_name,
                $phone,
                "user{$i}@email.com",
                $notes,
                $birthday,
                $now
            );
        }

        return $data;
    }
}
