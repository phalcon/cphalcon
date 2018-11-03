<?php

use Phalcon\Db\Reference;

/**
 * Fixture for Reference method
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
 * @package   Helper\Dialect\PostgresqlTrait
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

return
    new Reference('test_describereferences', [
        'referencedTable'   => 'foreign_key_parent',
        'referencedSchema' => 'phalcon_test',
        'columns'           => ['child_int'],
        'referencedColumns' => ['refer_int'],
        'onUpdate'          => 'CASCADE',
        'onDelete'          => 'RESTRICT',
    ]);
