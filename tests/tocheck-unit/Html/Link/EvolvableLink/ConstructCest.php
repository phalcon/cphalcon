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

namespace Phalcon\Test\Unit\Html\Link\EvolvableLink;

use Phalcon\Html\Link\EvolvableLink;
use Psr\Link\EvolvableLinkInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\EvolvableLink :: __construct()
     *
     * @since  2019-11-02
     */
    public function linkEvolvableLinkConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - __construct()');

        $link = new EvolvableLink();

        $class = EvolvableLinkInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
