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

namespace Phalcon\Test\Unit\Html\Link\EvolvableLinkProvider;

use Phalcon\Html\Link\EvolvableLinkProvider;
use Psr\Link\EvolvableLinkProviderInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\EvolvableLinkProvider :: __construct()
     *
     * @since  2019-11-02
     */
    public function linkEvolvableLinkConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLinkProvider - __construct()');

        $link = new EvolvableLinkProvider();

        $class = EvolvableLinkProviderInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
