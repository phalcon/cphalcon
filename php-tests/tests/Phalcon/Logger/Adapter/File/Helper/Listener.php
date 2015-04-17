<?php
/**
 * Listener.php
 * Logger_Adapter_File_Helper_Listener
 *
 * Tests the \Phalcon\Logger\Adapter\File\HelperListener component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
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

namespace Phalcon\Test\Logger\Adapter\File\Helper;

use \Phalcon\Logger\Adapter\File as PhLoggerAdapterFile;

class Listener
{
    protected $logger;

    public function __construct($fileName)
    {
        $this->logger = new PhLoggerAdapterFile($fileName);
    }

    public function afterQuery($event, $connection)
    {
        $this->logger->log($connection->getSQLStatement());
    }

    public function getProfiler()
    {
        return $this->profiler;
    }

    public function getLogger()
    {
        return $this->logger;
    }
}
