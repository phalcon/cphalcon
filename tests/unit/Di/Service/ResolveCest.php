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

namespace Phalcon\Test\Unit\Di\Service;

use Phalcon\Di\Exception\ServiceResolutionException;
use Phalcon\Di\Service;
use UnitTester;

/**
 * Class ResolveCest
 */
class ResolveCest
{
    /**
     * Tests Phalcon\Di\Service :: resolve()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diServiceResolve(UnitTester $I)
    {
        $I->wantToTest('Di\Service - resolve()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Di\Service :: resolve() - fail
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diServiceResolveFail(UnitTester $I)
    {
        $service1 = new Service(1);

        $I->wantToTest('Di\Service - resolve() - fail');
        $I->expectException(ServiceResolutionException::class, function() use ($service1) {
            $service1->resolve();
        });
    }
}
