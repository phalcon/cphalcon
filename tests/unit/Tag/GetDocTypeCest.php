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

class GetDocTypeCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: getDocType() - 3.2
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDoctypeSet32Final(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML32);
    }


    /**
     * Tests Phalcon\Tag :: getDocType() - 4.01 Strict
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet401(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML401_STRICT);
    }

    /**
     * Tests Phalcon\Tag :: getDocType() - 4.01 Transitional
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet401Transitional(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML401_TRANSITIONAL);
    }

    /**
     * Tests Phalcon\Tag :: getDocType() - 4.01 Frameset
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet401Frameset(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML401_FRAMESET);
    }

    /**
     * Tests Phalcon\Tag :: getDocType() - 5
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet5(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML5);
    }

    /**
     * Tests Phalcon\Tag :: getDocType() - 1.0 Strict
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet10Strict(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML10_STRICT);
    }

    /**
     * Tests Phalcon\Tag :: getDocType() - 1.0 Transitional
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet10Transitional(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML10_TRANSITIONAL);
    }

    /**
     * Tests Phalcon\Tag :: getDocType() - 1.0 Frameset
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet10Frameset(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML10_FRAMESET);
    }

    /**
     * Tests Phalcon\Tag :: getDocType() - 1.1
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet11(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML11);
    }

    /**
     * Tests Phalcon\Tag :: getDocType() - 2.0
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet20(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML20);
    }

    /**
     * Tests Phalcon\Tag :: getDocType() - wrong setting
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSetWrongParameter(UnitTester $I)
    {
        $this->runDoctypeTest($I, 99);
    }
}
