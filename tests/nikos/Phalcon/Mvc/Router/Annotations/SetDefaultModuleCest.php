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

namespace Phalcon\Test\Unit\Mvc\Router\Annotations;

use UnitTester;

/**
 * Class SetDefaultModuleCest
 */
class SetDefaultModuleCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: setDefaultModule()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcRouterAnnotationsSetDefaultModule(UnitTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - setDefaultModule()');
        $I->skipTest('Need implementation');
    }
}
