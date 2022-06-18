/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subway.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: GHeeJeon <jhjeon_99@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:41:03 by GHeeJeon          #+#    #+#             */
/*   Updated: 2022/06/19 04:48:36 by GHeeJeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	start_station[30];
char	dest_station[30];

void	print_string(char string[30])
{
	int		i;

	i = 0;
	while (string[i] != 0)
	{
		printf("%c", string[i]);
		i++;
	}
}

int	search_name(char temp[1024], char string[30])
{
	int	i;
	int	j;

	if (string[0] == '\0')
		return (0);
	i = 0;
	while (temp[i] != '\0')
	{
		j = 0;
		while (temp[i + j] == string[j] && temp[i + j] != '\0')
		{
			if (temp[i + j + 1] == '\n' && string[j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_validate_name(char string[30])
{
	char	temp[1024];
	FILE	*fp;

	fp = fopen("data/역이름.csv", "r");
	if(fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return (-1);
	}

	if (fp != NULL)
    {
        while (!feof(fp)){
            fgets(temp, 1024, fp);
			if (search_name(temp, string) == 1)
			{
				fclose(fp);
				return (1);
			}
        }
    }
	fclose(fp);
	return (0);
}

int	get_start_station()
{
	printf("출발역을 입력해주세요: ");
	scanf("%[^\n]", start_station);
	while (is_validate_name(start_station) == 0)
	{
		printf("그런 역은 없어요!\n다시 입력해주세요.\n\n");
		printf("출발역을 입력해주세요: ");
		getchar();
		scanf("%[^\n]", start_station);
		printf("\n");
	}
	return (0);
}

int	get_dest_station()
{
	printf("도착역을 입력해주세요: ");
	getchar();
	scanf("%[^\n]", dest_station);
	while (is_validate_name(dest_station) == 0)
	{
		printf("그런 역은 없어요!\n다시 입력해주세요.\n\n");
		printf("도착역을 입력해주세요: ");
		getchar();
		scanf("%[^\n]", dest_station);
		printf("\n");
	}
	return (0);
}

int	main(void)
{
	get_start_station();
	get_dest_station();
	while (strcmp(start_station, dest_station) == 0)
	{
		printf("출발역과 도착역이 같아요!\n다시 입력해주세요.\n\n");
		getchar();
		get_start_station();
		get_dest_station();
	}
	//get_option();
	//calculate();
	//print_result();

	return (0);
}
