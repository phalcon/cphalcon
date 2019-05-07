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

namespace Phalcon\Test\Unit\Paginator\Repository;

use UnitTester;

class GetPreviousCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: getPrevious()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function paginatorRepositoryGetPrevious(UnitTester $I)
    {
        $I->wantToTest('Paginator\Repository - getPrevious()');

        $I->skipTest('Need implementation');
    }
}
