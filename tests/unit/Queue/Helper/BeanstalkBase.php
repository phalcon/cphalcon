<?php

namespace Phalcon\Test\Unit\Queue\Helper;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Queue\Beanstalk;

/**
 * \Phalcon\Test\Unit\Queue\Helper\BeanstalkBase
 * Base class for Phalcon\Queue\Beanstalk component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class BeanstalkBase extends UnitTest
{
    /**
     * @var Beanstalk
     */
    protected $client = null;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        if (!extension_loaded('yaml')) {
            $this->markTestSkipped('Warning: yaml extension is not loaded');
        }

        if (!defined('TEST_BT_HOST') || !defined('TEST_BT_PORT')) {
            $this->markTestSkipped('TEST_BT_HOST and/or TEST_BT_PORT env variables are not defined');
        }

        $this->client = new Beanstalk([
            'host' => TEST_BT_HOST,
            'port' => TEST_BT_PORT
        ]);

        try {
            @$this->client->connect();
        } catch (\Exception $e) {
            $this->markTestSkipped($e->getMessage());
        }
    }
}
