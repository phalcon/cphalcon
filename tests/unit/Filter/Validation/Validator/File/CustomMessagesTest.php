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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\File;

use Phalcon\Filter\Validation\Validator\File;
use Phalcon\Filter\Validation\Validator\File\Resolution\Equal as EqualResolution;
use Phalcon\Filter\Validation\Validator\File\Size\Equal as EqualFileSize;
use Phalcon\Tests\AbstractUnitTestCase;

final class CustomMessagesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorFileCustomMessages(): void
    {
        $options    = [
            'maxSize'          => '0.5M',
            'messageFileEmpty' => 'File is empty',
            'messageIniSize'   => 'Ini size is not valid',
            'messageValid'     => 'File is not valid',
        ];
        $file       = new File($options);
        $validators = $file->getValidators();

        /** @var File\AbstractFile $validator */
        foreach ($validators as $validator) {
            $expected = $options['messageFileEmpty'];
            $actual   = $validator->getMessageFileEmpty();
            $this->assertSame($expected, $actual);

            $expected = $options['messageIniSize'];
            $actual   = $validator->getMessageIniSize();
            $this->assertSame($expected, $actual);

            $expected = $options['messageValid'];
            $actual   = $validator->getMessageValid();
            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorFileEqualSize(): void
    {
        $options = [
            'equalSize'       => '1M',
            'messageEqualSize' => 'File does not have the expected size',
        ];
        $file       = new File($options);
        $validators = $file->getValidators();

        $this->assertCount(1, $validators);
        $this->assertInstanceOf(EqualFileSize::class, $validators[0]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorFileEqualResolution(): void
    {
        $options = [
            'equalResolution'        => '1920x1080',
            'messageEqualResolution' => 'File does not have the expected resolution',
        ];
        $file       = new File($options);
        $validators = $file->getValidators();

        $this->assertCount(1, $validators);
        $this->assertInstanceOf(EqualResolution::class, $validators[0]);
    }
}
