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

namespace Phalcon\Test\Unit\Annotations\AdapterFactory;

use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Annotations\AdapterFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-19
     */
    public function annotationsAdapterFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Annotations\AdapterFactory - newInstance()');

        $I->skipTest('Need implementation');
    }
}
