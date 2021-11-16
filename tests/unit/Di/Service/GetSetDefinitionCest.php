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

namespace Phalcon\Tests\Unit\Di\Service;

use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use Phalcon\Support\Collection;
use UnitTester;

/**
 * Class GetSetDefinitionCest
 *
 * @package Phalcon\Tests\Unit\Di\Service
 */
class GetSetDefinitionCest
{
    /**
     * Tests Phalcon\Di\Service :: setDefinition()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceGetSetDefinition(UnitTester $I)
    {
        $I->wantToTest('Di\Service - getDefinition()/setDefinition()');

        $service = new Service(Escaper::class, false);

        $expected = Escaper::class;
        $actual   = $service->getDefinition();
        $I->assertEquals($expected, $actual);

        $service->setDefinition(Collection::class);

        $expected = Collection::class;
        $actual   = $service->getDefinition();
        $I->assertEquals($expected, $actual);
    }
}
