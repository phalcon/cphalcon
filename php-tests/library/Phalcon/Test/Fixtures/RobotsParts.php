<?php
/**
 * RobotsParts.php
 * Phalcon_Test_Fixtures_RobotsParts
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

class RobotsParts
{
    public static function get()
    {
        $data[] = "(1, 1, 1)";
        $data[] = "(2, 1, 2)";
        $data[] = "(3, 1, 3)";

        return $data;
    }
}
