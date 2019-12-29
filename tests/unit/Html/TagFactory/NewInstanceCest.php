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

namespace Phalcon\Test\Unit\Html\TagFactory;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Factory\Exception;
use Phalcon\Html\Helper\Anchor;
use Phalcon\Html\Helper\AnchorRaw;
use Phalcon\Html\Helper\Body;
use Phalcon\Html\Helper\Button;
use Phalcon\Html\Helper\Close;
use Phalcon\Html\Helper\Element;
use Phalcon\Html\Helper\ElementRaw;
use Phalcon\Html\Helper\Form;
use Phalcon\Html\Helper\Img;
use Phalcon\Html\Helper\Label;
use Phalcon\Html\Helper\TextArea;
use Phalcon\Html\TagFactory;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Tag\TagFactory :: newInstance() - services
     *
     * @dataProvider getData
     */
    public function filterTagFactoryNewInstanceServices(UnitTester $I, Example $example)
    {
        $I->wantToTest('Tag\TagLocatorFactory - newInstance() - services ' . $example[0]);
        $escaper = new Escaper();
        $factory = new TagFactory($escaper);
        $service = $factory->newInstance($example[0]);

        $class = $example[1];
        $I->assertInstanceOf($class, $service);
    }

    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance() - exception
     *
     * @throws Exception
     * @since  2019-05-04
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function filterTagFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Tag\TagFactory - newInstance() - exception');

        $I->expectThrowable(
            new Exception('Service unknown is not registered'),
            function () {
                $escaper = new Escaper();
                $factory = new TagFactory($escaper);
                $service = $factory->newInstance('unknown');
            }
        );
    }

    /**
     * Returns the example data
     */
    private function getData(): array
    {
        return [
            ['a', Anchor::class],
            ['aRaw', AnchorRaw::class],
            ['body', Body::class],
            ['button', Button::class],
            ['close', Close::class],
            //            ['doctype'],
            ['element', Element::class],
            ['elementRaw', ElementRaw::class],
            ['form', Form::class],
            //            ['head'],
            ['img', Img::class],
            //            ['input'],
            ['label', Label::class],
            //            ['link'],
            //            ['script'],
            //            ['style'],
            ['textarea', TextArea::class],
            //            ['title'],
        ];
    }
}
