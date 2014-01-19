<?php
/**
 * SqliteTest.php
 * Logger_Adapter_File_SqliteTest
 *
 * Tests the \Phalcon\Logger\Adapter\File component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
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

namespace Phalcon\Test\Logger\Adapter\File;

use Phalcon\Test\Logger\Adapter\File\Helper\Model as LoggerAdapterFileHelperModel;

class SqliteTest extends LoggerAdapterFileHelperModel
{
    public function setUp()
    {
        parent::setUp();

        $this->setDb('sqlite');

    }
}