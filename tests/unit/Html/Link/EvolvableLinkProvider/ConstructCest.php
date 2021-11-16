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

namespace Phalcon\Tests\Unit\Html\Link\EvolvableLinkProvider;

use Phalcon\Html\Link\EvolvableLinkProvider;
use Psr\Link\EvolvableLinkProviderInterface;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\EvolvableLinkProvider
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\EvolvableLinkProvider :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkEvolvableLinkConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLinkProvider - __construct()');

        $link = new EvolvableLinkProvider();

        $class = EvolvableLinkProviderInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
