<?php

namespace Phalcon\Test\Unit\Forms\Element;

use Phalcon\Forms\Element\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Forms\Element\TextTest
 * Tests the \Phalcon\Test\Unit\Forms\Element\Text component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Forms\Element
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TextTest extends UnitTest
{
    /**
     * Tests Text::render
     *
     * @issue  10398
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-07-17
     */
    public function testCreatingTextElementWithNameSimilarToTheFormMethods()
    {
        $this->specify('Text::render does not return expected result', function ($name) {
            $element = new Text($name);

            expect($element->getName())->equals($name);
            expect($element->render())->equals(sprintf('<input type="text" id="%s" name="%s" />', $name, $name));
            expect($element->getValue())->null();
        }, ['examples' => $this->nameLikeFormMethodsProvider()]);
    }

    protected function nameLikeFormMethodsProvider()
    {
        return [
            ['validation'],
            ['action'],
            ['useroption'],
            ['useroptions'],
            ['entity'],
            ['elements'],
            ['messages'],
            ['messagesfor'],
            ['label'],
            ['value'],
            ['di'],
            ['eventsmanager'],
        ];
    }
}
