<?php
declare(strict_types=1);

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

/**
 * Trait BeanstalkTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
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
                'port' => DATA_BEANSTALKD_PORT,
            ]
        );

        try {
            @$this->client->connect();

            /**
             * Clean up the tubes
             */
            $this->client->choose('beanstalk-test-1');
            while ($job = $this->client->peekReady()) {
                echo ".";
                $job->delete();
            }

            $this->client->choose('beanstalk-test-2');
            while ($job = $this->client->peekReady()) {
                echo ".";
                $job->delete();
            }
        } catch (\Exception $e) {
            $I->skipTest($e->getMessage());
        }
    }
}
