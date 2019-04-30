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

namespace Phalcon\Test\Integration\Session\Adapter\Stream;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

/**
 * Class OpenCest
 */
class OpenCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Stream :: open()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterStreamOpen(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - open()');
        $adapter = $this->getSessionStream();
        $actual  = $adapter->open(cacheDir(), 'test1');
        $I->assertTrue($actual);
    }
}
