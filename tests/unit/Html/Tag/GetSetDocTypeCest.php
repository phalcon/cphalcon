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

namespace Phalcon\Test\Unit\Html\Tag;

use Codeception\Example;
use Phalcon\Html\Tag;
use UnitTester;

/**
 * Class GetSetDocTypeCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class GetSetDocTypeCest
{
    /**
     * Tests Phalcon\Html\Tag :: getDocType()/setDocType()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @dataProvider getDocTypes
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2018-11-13
     */
    public function htmlTagGetSetDocType(UnitTester $I, Example $example)
    {
        $I->wantToTest(sprintf('Html\Tag - getDocType()/setDocType() - %s', $example['name']));

        $tag = new Tag();
        $tag->setDocType($example['value']);
        $expected = $example['string'];
        $actual   = $tag->getDocType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getDocTypes(): array
    {
        return [
            [
                'name'   => 'HTML_32',
                'value'  => 1,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">" . PHP_EOL,
            ],
            [
                'name'   => 'HTML401_STRICT',
                'value'  => 2,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"" . PHP_EOL .
                    "\t\"http://www.w3.org/TR/html4/strict.dtd\">" . PHP_EOL,
            ],
            [
                'name'   => 'HTML401_TRANSITIONAL',
                'value'  => 3,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"" . PHP_EOL .
                    "\t\"http://www.w3.org/TR/html4/loose.dtd\">" . PHP_EOL,
            ],
            [
                'name'   => 'HTML401_FRAMESET',
                'value'  => 4,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"" . PHP_EOL .
                    "\t\"http://www.w3.org/TR/html4/frameset.dtd\">" . PHP_EOL,
            ],
            [
                'name'   => 'HTML5',
                'value'  => 5,
                'string' => "<!DOCTYPE html>" . PHP_EOL,
            ],
            [
                'name'   => 'XHTML10_STRICT',
                'value'  => 6,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" . PHP_EOL .
                    "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" . PHP_EOL,
            ],
            [
                'name'   => 'XHTML10_TRANSITIONAL',
                'value'  => 7,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"" . PHP_EOL .
                    "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" . PHP_EOL,
            ],
            [
                'name'   => 'XHTML10_FRAMESET',
                'value'  => 8,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"" . PHP_EOL .
                    "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">" . PHP_EOL,
            ],
            [
                'name'   => 'XHTML11',
                'value'  => 9,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" . PHP_EOL .
                    "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" . PHP_EOL,
            ],
            [
                'name'   => 'XHTML20',
                'value'  => 10,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"" . PHP_EOL .
                    "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">" . PHP_EOL,
            ],
            [
                'name'   => 'XHTML5',
                'value'  => 11,
                'string' => "<!DOCTYPE html>" . PHP_EOL,
            ],
        ];
    }
}
