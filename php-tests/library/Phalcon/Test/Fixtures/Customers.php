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
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test\Fixtures;
    
class Customers
{
    public static function get($records = null)
    {
        $template = "(%s, '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', "
                  . "'%s', '%s', '%s', '0')";

        $total      = (is_null($records)) ? 100 : intval($records);
        $documentId = 1;
        $customerId = 1;
        $data       = array();

        for ($i = 1; $i <= $total; $i++) {
            $documentId = ($documentId > 4)  ? 1 : ($documentId + 1);
            $customerId = ($customerId > 3) ? 1 : ($customerId + 1);
            $firstName  = 'John ' . $i;
            $lastName   = 'Doe ' . $i;
            $phone      = '555-444-' . $i;
            $notes      = 'Notes ' . $i;
            $birthday   = date('Y-m-d');
            $status     = ($i % 3) ? 'A' : 'I';
            $now        = date('Y-m-d H:i:s');
            $credit     = $i * 10;

            $data[] = sprintf(
                $template,
                $i,
                $customerId,
                $documentId,
                $firstName,
                $lastName,
                $phone,
                "user{$i}@email.com",
                $notes,
                $status,
                $birthday,
                $credit,
                $now
            );
        }

        return $data;
    }
}
