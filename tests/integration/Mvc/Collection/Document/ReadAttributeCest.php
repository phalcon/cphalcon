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

namespace Phalcon\Test\Integration\Mvc\Collection\Document;

use IntegrationTester;

/**
 * Class ReadAttributeCest
 */
class ReadAttributeCest
{
    /**
     * Tests Phalcon\Mvc\Collection\Document :: readAttribute()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionDocumentReadAttribute(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection\Document - readAttribute()');
        $I->skipTest('Need implementation');
    }
}
