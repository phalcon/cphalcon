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
use Phalcon\Di\ServiceInterface;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Di\Service
 */
class ConstructCest
{
    /**
     * Unit Tests Phalcon\Di\Service :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceConstruct(UnitTester $I)
    {
        $I->wantToTest('Di\Service - __construct()');

        $service = new Service(Escaper::class, false);
        $class   = ServiceInterface::class;
        $I->assertInstanceOf($class, $service);
    }
}
