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
use UnitTester;

use function spl_object_hash;

class SetSharedInstanceCest
{
    /**
     * Unit Tests Phalcon\Di\Service :: setSharedInstance()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diServiceSetSharedInstance(UnitTester $I)
    {
        $I->wantToTest('Di\Service - setSharedInstance()');

        $escaper = new Escaper();
        $service = new Service($escaper, true);
        $service->setSharedInstance($escaper);

        $expected = spl_object_hash($escaper);
        $actual   = spl_object_hash($service->resolve());
        $I->assertEquals($expected, $actual);
    }
}
