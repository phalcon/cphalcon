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

namespace Phalcon\Tests\Unit\Html\Link\EvolvableLink;

use Phalcon\Html\Link\EvolvableLink;
use Psr\Link\EvolvableLinkInterface;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Html\Link\EvolvableLink
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Html\Link\EvolvableLink :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function linkEvolvableLinkConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Link\EvolvableLink - __construct()');

        $link = new EvolvableLink();

        $class = EvolvableLinkInterface::class;
        $I->assertInstanceOf($class, $link);
    }
}
