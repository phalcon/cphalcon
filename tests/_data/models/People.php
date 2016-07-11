<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * \Phalcon\Test\Models\People
 * People model class
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class People extends Model
{
    public $cedula;
    public $tipo_documento_id;
    public $nombres;
    public $telefono;
    public $direccion;
    public $email;
    public $fecha_nacimiento;
    public $ciudad_id;
    public $cupo;
    public $estado;
    public $creado_at;

    public function getSource()
    {
        return 'personas';
    }
}
