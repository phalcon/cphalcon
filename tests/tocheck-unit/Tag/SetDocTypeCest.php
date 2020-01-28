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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class SetDocTypeCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: setDocType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function tagSetDocType(UnitTester $I)
    {
        $I->wantToTest('Tag - setDocType()');
        $this->runDoctypeTest($I, Tag::HTML32);
    }
}
