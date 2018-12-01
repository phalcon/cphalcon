<?php

namespace Phalcon\Test\Unit\Queue\Helper;

use Phalcon\Queue\Beanstalk;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Queue\Helper\BeanstalkBase
 * Base class for Phalcon\Queue\Beanstalk component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Phalcon Team <team@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
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

        if (!defined('DATA_BEANSTALKD_HOST') || !defined('DATA_BEANSTALKD_PORT')) {
            $this->markTestSkipped('DATA_BEANSTALKD_HOST and/or DATA_BEANSTALKD_PORT env variables are not defined');
        }

        $this->client = new Beanstalk([
            'host' => DATA_BEANSTALKD_HOST,
            'port' => DATA_BEANSTALKD_PORT
        ]);

        try {
            @$this->client->connect();
        } catch (\Exception $e) {
            $this->markTestSkipped($e->getMessage());
        }
    }
}
