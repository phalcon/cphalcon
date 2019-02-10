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

namespace Phalcon\Test\Unit\Mvc\Model\MetaData\Apcu;

use UnitTester;

/**
 * Class SetEmptyStringAttributesCest
 */
class SetEmptyStringAttributesCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Apcu :: setEmptyStringAttributes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcModelMetaDataApcuSetEmptyStringAttributes(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Apcu - setEmptyStringAttributes()');
        $I->skipTest('Need implementation');
    }
}
