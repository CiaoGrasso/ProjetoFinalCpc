from django.shortcuts import render
from django.http import JsonResponse
from .models import PotentiometerDataMixer, PotentiometerDataInput

def atualizar_dados(request):
    try:
        numero_serial = request.GET.get('numero_serial')
        instrumento_db = request.GET.get('instrumento_db')
        mixer_db = request.GET.get('mixer_db')
        mute_state = request.GET.get('mute_state')

        if not numero_serial:
            return JsonResponse({'status': 'error', 'message': 'Missing serial number'}, status=400)

        if mixer_db is not None and mute_state is not None:
            data, created = PotentiometerDataMixer.objects.update_or_create(
                numero_serial=numero_serial,
                defaults={
                    'instrumento_db': instrumento_db,
                    'mixer_db': mixer_db,
                    'mute_state': bool(int(mute_state)),
                }
            )

        if instrumento_db is not None:
            data, created = PotentiometerDataInput.objects.update_or_create(
                numero_serial=numero_serial,
                defaults={
                    'instrumento_db': instrumento_db,
                }
            )

        return JsonResponse({'status': 'success'})

    except ValueError as e:
        return JsonResponse({'status': 'error', 'message': 'Invalid data format'}, status=400)
    except Exception as e:
        return JsonResponse({'status': 'error', 'message': str(e)}, status=500)
