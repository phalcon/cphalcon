<?php
/**
 * DbListener.php
 * \Phalcon\Logger\Helper\DbListener
 *
 * Tests the \Phalcon\Logger\Helper\DbListener component
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
use \Phalcon\Logger\Adapter\File as PhFLg;

class Logger_Helper_DbListener
{

	protected $_logger;

	public function __construct($fileName)
    {
		$this->_logger = new PhFLg($fileName);
	}

	public function afterQuery($event, $connection)
	{
		$this->_logger->log($connection->getSQLStatement());
	}

	public function getProfiler()
	{
		return $this->_profiler;
	}

	public function getLogger()
	{
		return $this->_logger;
	}
}
