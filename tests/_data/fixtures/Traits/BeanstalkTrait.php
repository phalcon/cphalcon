<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Queue\Beanstalk;
use UnitTester;
use function var_dump;

trait BeanstalkTrait
{
    /**
     * @var Beanstalk
     */
    protected $client = null;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('yaml');

        if (!defined('DATA_BEANSTALKD_HOST') || !defined('DATA_BEANSTALKD_PORT')) {
            $I->skipTest('DATA_BEANSTALKD_HOST and/or DATA_BEANSTALKD_PORT env variables are not defined');
        }

        $this->client = new Beanstalk(
            [
                'host' => DATA_BEANSTALKD_HOST,
                'port' => DATA_BEANSTALKD_PORT
            ]
        );

        try {
            @$this->client->connect();
        } catch (\Exception $e) {
            $I->skipTest($e->getMessage());
        }
    }
}
