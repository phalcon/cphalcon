<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Link\EvolvableLinkProvider;

use Phalcon\Link\EvolvableLinkProvider;
use Psr\Link\EvolvableLinkProviderInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Link\EvolvableLinkProvider :: __construct()
     *
     * @since  2019-06-15
     */
    public function linkEvolvableLinkConstruct(UnitTester $I)
    {
        $I->wantToTest('Link\EvolvableLinkProvider - __construct()');

        $link = new EvolvableLinkProvider();

        $class = EvolvableLinkProviderInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
