<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Session\Adapter\Stream;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class CloseCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Stream :: close()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterStreamClose(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - close()');

        $adapter = $this->newService('sessionStream');
        $actual  = $adapter->close();
        $I->assertTrue($actual);
    }
}
