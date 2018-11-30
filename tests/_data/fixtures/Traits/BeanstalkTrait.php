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

        if (!defined('TEST_BT_HOST') || !defined('TEST_BT_PORT')) {
            $I->skipTest('TEST_BT_HOST and/or TEST_BT_PORT env variables are not defined');
        }

        $this->client = new Beanstalk(
            [
                'host' => TEST_BT_HOST,
                'port' => TEST_BT_PORT
            ]
        );

        try {
            @$this->client->connect();
        } catch (\Exception $e) {
            $I->skipTest($e->getMessage());
        }
    }
}
