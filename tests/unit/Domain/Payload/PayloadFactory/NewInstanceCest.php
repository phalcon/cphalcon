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

namespace Phalcon\Test\Unit\Domain\Payload\PayloadFactory;

use Phalcon\Domain\Payload\PayloadFactory;
use Phalcon\Domain\Payload\PayloadInterface;
use UnitTester;

class NewInstanceCest
{
    /**
     * Unit Tests Phalcon\Domain\Payload\PayloadFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-24
     */
    public function httpPayloadPayloadFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Domain\Payload\PayloadFactory - newInstance()');

        $factory = new PayloadFactory();
        $payload = $factory->newInstance();

        $I->assertInstanceOf(
            PayloadInterface::class,
            $payload
        );
    }
}
