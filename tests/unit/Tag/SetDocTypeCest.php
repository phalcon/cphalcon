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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

/**
 * Class SetDocTypeCest
 */
class SetDocTypeCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: setDocType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function tagSetDocType(UnitTester $I)
    {
        $I->wantToTest("Tag - setDocType()");
        $this->runDoctypeTest($I, Tag::HTML32);
    }
}
